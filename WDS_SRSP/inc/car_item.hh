#ifndef CAR_ITEM_HH
#define CAR_ITEM_HH

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QGraphicsScene>
#include "memsdata.hh"

/*!
 * \brief The CarItem class
 * Klasa odpowiedzialna za zarządzanie obiektem samochodu,
 * poruszanie samochodu w prawo lub lewo na podstaie odczytanych danych z mikrokontrolera
 */
class CarItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /*!
     * \brief CarItem
     * Konstruktor klasy
     */
    CarItem();

    /*!
     * \brief resetPosition
     * Funckja odpowiedzilana za ustawienie początkowej pozycji samochodu
     */
    void resetPosition();
    /*!
     * \brief move
     * Klasa odpowiedzialna za ustawienie nowej pozycji samochodu
     * \param data - w parametrze przechowywane dane odpowiedzialne za poruszanie odczytane z mikrokontrolera
     */
    void move(moveData data);

public slots:
    /*!
     * \brief onMoveCar
     * Slot odpowiedzlany za poruszanie samochodu
     */
    void onMoveCar();
    /*!
     * \brief onStopCar
     * Slot odpowiedzialny za zatrzymanie samochodu
     */
    void onStopCar();

private:
    bool _stopCar; //! Flaga sygnalizująca zatrzymanie ruchu samochodu
};

#endif // CAR_ITEM_HH
