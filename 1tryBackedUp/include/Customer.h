#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <vector>
#include <string>
#include "Workout.h"

class Customer{
public:
    // no delete operator and move constructor because no memory is allocated from Heap

    // Main Constructor
    Customer(std::string c_name, int c_id);
    virtual std::vector<int> order(const std::vector<Workout> &workout_options)=0;
    virtual std::string toString() const = 0;
    std::string getName() const;
    int getId() const;

    virtual ~Customer();
    virtual Customer& operator=(const Customer& rhs);
    virtual Customer& operator=(Customer&& rhs);
    Customer(const Customer& rhs);
    Customer(Customer&& rhs);
    virtual void stole();

private:
    const std::string name;
    const int id;
};

// serial number from 0
// as long as customer has a workout session
// customer that can't get order: no order at all
// when there's choice, order with smallest id
// id is unique name isn't



class SweatyCustomer : public Customer {
public:
	SweatyCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Workout> &workout_options);
    std::string toString() const;

    ~SweatyCustomer();
    SweatyCustomer& operator=(const SweatyCustomer& rhs);
    SweatyCustomer& operator=(SweatyCustomer&& rhs);
    SweatyCustomer(const SweatyCustomer& other);
    SweatyCustomer(SweatyCustomer&& rhs);


private:
};


class CheapCustomer : public Customer {
public:
	CheapCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Workout> &workout_options);
    std::string toString() const;

    ~CheapCustomer();
    CheapCustomer& operator=(const CheapCustomer& rhs);
    CheapCustomer& operator=(CheapCustomer&& rhs);
    CheapCustomer(const CheapCustomer& rhs);
    CheapCustomer(CheapCustomer&& rhs);
private:
};


class HeavyMuscleCustomer : public Customer {
public:
	HeavyMuscleCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Workout> &workout_options);
    std::string toString() const;

    ~HeavyMuscleCustomer();
    HeavyMuscleCustomer& operator=(const HeavyMuscleCustomer& rhs);
    HeavyMuscleCustomer& operator=(HeavyMuscleCustomer&& rhs);
    HeavyMuscleCustomer(const HeavyMuscleCustomer& rhs);
    HeavyMuscleCustomer(HeavyMuscleCustomer&& rhs);


private:
};


class FullBodyCustomer : public Customer {
public:
	FullBodyCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Workout> &workout_options);
    std::string toString() const;

    ~FullBodyCustomer();
    FullBodyCustomer& operator=(const FullBodyCustomer& rhs);
    FullBodyCustomer& operator=(FullBodyCustomer&& rhs);
    FullBodyCustomer(const FullBodyCustomer& rhs);
    FullBodyCustomer(FullBodyCustomer&& rhs);

private:
};


#endif