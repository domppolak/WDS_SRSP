#ifndef ROAD_ITEM_HH
#define ROAD_ITEM_HH

#define MAX_SPEED 100
#define MIN_SPEED 10

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include "memsdata.hh"

/*!
 * \brief The RoadItem class
 * Klasa obsługująca animację drogi, ustawienie prędkości animacji przesowania drogi.
 */
class RoadItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    /*!
     * \brief RoadItem
     * Konstruktor klasy
     */
    RoadItem();
    /*!
     * \brief ~RoadItem
     * Destruktor klasy
     */
    ~RoadItem();
    /*!
     * \brief setSpeed
     * Funckja odpowiedzialna zaustawienie szybkości animacji drogi
     * \param speed - szybkość animacji
     */
    void setSpeed(const int &speed);
    /*!
     * \brief getSpeed
     * \return zwraca szybkość animacji drogi
     */
    int getSpeed() const;
    /*!
     * \brief speedChanged
     * Funckja odpowiedzialna za dynamiczną zmianę prędkości animacji,
     * w zależności od odczytów z mikrokontrolera
     * \param data - w parametrze przechowywane dane odpowiedzialne za poruszanie odczytane z mikrokontrolera
     */
    void speedChanged(moveData data);

public slots:
    /*!
     * \brief move
     * Slot odpowiedzialny za ustawienie nowej pozycji animacji drogi
     */
    void move();
    /*!
     * \brief startAnimation
     * Slot uruchamiający animację drogi
     */
    void startAnimation();
    /*!
     * \brief stopAnimation
     * Slot zatrzymujący animację drogi
     */
    void stopAnimation();


private:
    int _speed; //! Prędkość animacji drogi
    QTimer *_timer; //! Wskaźnik na timer

};

#endif // ROAD_ITEM_HH
