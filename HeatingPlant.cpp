#include "HeatingPlant.h"


HeatingPlant::HeatingPlant():Client()
{

}

HeatingPlant::HeatingPlant(int _difficulty)
{

    this->name="Heating Plant";
    if(_difficulty==3)  //trudny
    {
        this->averageOrder = new Order(new CoalTypeA(4000,400), new CoalTypeB(4000,300));
    }
    else if (_difficulty==2)    //średni
    {
        this->averageOrder = new Order(new CoalTypeA(4500,500), new CoalTypeB(4500,350));
    }
    else    //łatwy (domyślnie)
    {
        this->averageOrder = new Order(new CoalTypeA(5000,600), new CoalTypeB(5000,400));
    }
}

Order* HeatingPlant::MakeOrder(int _date)
{
    Order *newOrder = new Order();
    if((_date%12+1)==1||(_date%12+1)==2||(_date%12+1)==3||(_date%12+1)==10||(_date%12+1)==11||(_date%12+1)==0)
    {
        newOrder->GetCoalA()->SetAmount(2*(this->averageOrder->GetCoalA()->GetAmount()*(1+(rand()%50-25)/100)));
        newOrder->GetCoalA()->SetPrice((this->averageOrder->GetCoalA()->GetPrice()*(1+(rand()%20-10)/100)));
        newOrder->GetCoalB()->SetAmount(2*(this->averageOrder->GetCoalB()->GetAmount()*(1+(rand()%50-25)/100)));
        newOrder->GetCoalB()->SetPrice((this->averageOrder->GetCoalB()->GetPrice()*(1+(rand()%20-10)/100)));
    }
    else
    {
        newOrder->GetCoalA()->SetAmount((this->averageOrder->GetCoalA()->GetAmount()*(1+(rand()%50-25)/100)));
        newOrder->GetCoalA()->SetPrice((this->averageOrder->GetCoalA()->GetPrice()*(1+(rand()%20-10)/100)));
        newOrder->GetCoalB()->SetAmount((this->averageOrder->GetCoalB()->GetAmount()*(1+(rand()%50-25)/100)));
        newOrder->GetCoalB()->SetPrice((this->averageOrder->GetCoalB()->GetPrice()*(1+(rand()%20-10)/100)));
    }
    return newOrder;
}
