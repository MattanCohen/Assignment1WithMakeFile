#include "../include/Trainer.h"
#include "Customer.cpp"

using namespace std;

int currId=0;

//c-tor with given capacity. the lists will remain empty
Trainer::Trainer (int t_capacity):capacity(t_capacity),open(false),id(currId),accumulatedSalary(0){
    currId++;
}

//rule of 5:
//d-tor
Trainer::~Trainer() {
    this->stole();
}
//ass op.
Trainer& Trainer::operator=(const Trainer& rhs){
    if (&*this!=&rhs){
        capacity=rhs.capacity;
        open=rhs.open;
        customersList=rhs.customersList;
        orderList=rhs.orderList;
        id=rhs.id;
        accumulatedSalary=rhs.accumulatedSalary;
    }
    return *this;
}
//move ass op.
Trainer& Trainer::operator=(Trainer&& rhs){
    if (this!=&rhs){
        capacity=rhs.capacity;
        open=rhs.open;
        customersList=rhs.customersList;
        orderList=rhs.orderList;
        id=rhs.id;
        accumulatedSalary=rhs.accumulatedSalary;
        rhs.stole();
    }
    return *this;
}
//copy c-tor:
Trainer::Trainer(const Trainer& rhs):capacity(rhs.capacity),open(rhs.open),id(rhs.id),orderList(rhs.orderList),accumulatedSalary(rhs.accumulatedSalary){}
//move c-tor
Trainer::Trainer(Trainer&& rhs):capacity(rhs.capacity),open(rhs.open),id(rhs.id),orderList(rhs.orderList),accumulatedSalary(rhs.accumulatedSalary){
    if(this!=&rhs)
        rhs.stole();
}

void Trainer::stole() {
    delete this;
}







//returns trainer's capacity
int Trainer::getCapacity() const{return capacity;}

//adds customer. assumes trainer is available
void Trainer::addCustomer(Customer* customer){
    customersList.push_back(customer);
    //add customer's orders prices to trainer's salary
    for (int i=0; i<orderList.size(); i++)
        if (orderList.at(i).first==id)
            accumulatedSalary+= orderList.at(i).second.getPrice();
    }

//remove Customer with the identifing number "id" from trainer's customers list
void Trainer::removeCustomer(int id) {
        for (int i = 0; i < customersList.size(); i++)
            //trying to find the customer with id "id"
            if (customersList.at(i)->getId() == id) {
                customersList.erase(customersList.begin()+i);
                //reduct customer's orders prices from trainer's salary
                for (int j=0; j<orderList.size(); j++)
                    if (orderList.at(j).first==id)
                        accumulatedSalary-= orderList.at(j).second.getPrice();
                return;
            }
    }

//get the Customer with id "id" or null if doesn't exists
Customer* Trainer::getCustomer(int id){
    Customer* ans= nullptr;
    for (int i = 0; i < customersList.size(); i++)
            if (customersList.at(i)->getId() == id) {
                return customersList.at(i);
            }
        return ans;
    }

//returns customersList
vector<Customer*>& Trainer:: getCustomers(){
        return customersList;
    }

//returns orderList
vector<OrderPair>& Trainer:: getOrders(){
        return orderList;
    }

//overloading make_pair for pair<int,Workout> types, to change second=work to second=Workout(work)
//to avoid using the copy ass. op. since Workout objects contain only const values
//OrderPair& Trainer::make_Pair(const int cus_id, const Workout& work){
//    OrderPair paired=make_pair(cus_id, Workout(work));
//    OrderPair &ans=paired;
//    return ans;
//}

//order a workout from this trainer for the customer customer_id
//assumes customer_id belongs to this trainer and workout_ids exists in workout_options.
void Trainer:: order(const int customer_id,const vector<int>workout_ids,const vector<Workout>& workout_options){
    for (int i=0; i<workout_ids.size(); i++){
        int work_id=workout_ids.at(i);
        Workout work(workout_options.at(work_id));
        orderList.push_back(make_pair(customer_id,work));
        }
    }

//changes trainer's status to open. since they were closed, their lists will be empty
void Trainer::openTrainer(){
        open=true;
    }

//changes trainer's status to close. since they were open, close their lists
void Trainer:: closeTrainer(){
    open=false;
    customersList.clear();
    orderList.clear();
}

//computes and returns salary
int Trainer::getSalary(){return accumulatedSalary;}

//returns true iff trainer is open
bool Trainer::isOpen(){return open;}

//returns trainer's id
int Trainer::getId(){return id;};

