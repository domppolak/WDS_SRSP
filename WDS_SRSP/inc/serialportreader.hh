#ifndef SERIALPORTREADER_HH
#define SERIALPORTREADER_HH

#include <QObject>
#include <QSerialPort>
#include <QString>
#include <QSettings>
#include <QMutex>

#include "memsdata.hh"

/*!
 * \brief Klasa SerialPortReader
 *  Klasa odpowiedzialna za obsługę połączenia z mikrokontrolerem
 *  oraz odczyt danych
 */
class SerialPortReader : public QObject
{
    Q_OBJECT

public:
    /*!
     * \brief SerialPortReader
     * Konstruktor klasy
     * \param [in] parent - rodzic obiektu
     */
    explicit SerialPortReader(QObject *parent = nullptr);
    /*!
     * \brief ~SerialPortReader
     * Destruktor klasy
     */
    ~SerialPortReader();

    /*!
     * \brief getPortOpened
     * \return Zwraca wartość flagi otwarcia portu
     */
    bool getPortOpened() const { return this->_portOpened; }
    /*!
     * \brief getSerialSettings
     * Metoda umożliwia dostęp do ustawień portu szeregowego
     * \return Ustawienia portu szeregowego
     */
    QSettings* getSerialSettings() const { return this->_serialSettings; }
    /*!
     * \brief setPortOpened
     * Ustawia flagę na wartość przekazaną w argumencie funkcji
     * \param [in] state - wartość do ustawienia flagi otwarcia portu
     */
    void setPortOpened(const bool &state) {this->_portOpened = state; }

    /*!
     * \brief readData
     * Metoda odpowiedzialna za odczytywanie danych z mikrokontrolera
     * w sposób ciągły
     */
    void readData();

signals:
    /*!
     * \brief newData
     * Sygnał emitowany w momencie otrzymania nowych danych z mikrokontrolera
     * \param [in] Data - W parametrze przechowywane są dane otrzymane z mikrokontrolera
     */
    void newData(rawData Data);
    /*!
     * \brief portOpened
     * Sygnał emitowany w momencie otwarcia portu szeregowego
     */
    void portOpened();
    /*!
     * \brief portClosed
     * Sygnał emitowany w momencie zamknięcia portu szeregowego
     */
    void portClosed();
    /*!
     * \brief portError
     * Sygnał emitowany gdy następi błąd z komunikacją
     * \param [in ]errorMessage - informacja o błędzie
     */
    void portError(QString errorMessage);
    /*!
     * \brief finished
     * Sygnał emitowany gdy wątek zakończy swoją pracę
     */
    void finished();

public slots:
    /*!
     * \brief openSerialPort
     * Otwiera port szeregowanych na podstawie ustawienień
     * zapisanych w konfiguracji portu szeregowego. Gdy port zostanie
     * otwarty zostaje ustawiona flaga _portOpened na true i emitowany
     * jest sygnał portOpened().
     */
    void openSerialPort();
    /*!
     * \brief closeSerialPort
     * Zamyka port szeregowy jeżeli jest on otwarty. Ustawia flagę
     * _portOpened na false i emituje sygnał portClosed()
     */
    void closeSerialPort();
    /*!
     * \brief readDataFromSerial
     * Gdy danę są gotowane do odczytu ten slot jest wykonywany-
     * Odczytuje wszystkie dane z portu szeregowego i emituje je sygnałem newData(rawData)
     *
     * \return
     */
    int readDataFromSerial();
    /*!
     * \brief serialErrorHandler
     * Obsługuje błędy zgłaszane przez port szeregowy
     *  i emituje je poprzez sygnał portError()
     * \param [in] errorMessage - błąd zgłoszony przez port szeregowy
     */
    void serialErrorHandler(QSerialPort::SerialPortError errorMessage);

private:
    QSerialPort *_serialPort = nullptr; //! Uchwyt portu szeregowego
    QSettings *_serialSettings; //! Wskaźnik do ustawień portu szeregowego
    QMutex _mutex; //! Wskaźnik na mutex

    bool _portOpened = false; //! Flaga sygnalizująca czy port szeregowy jesy otwarty
};

#endif // COMMUNICATION_HH
