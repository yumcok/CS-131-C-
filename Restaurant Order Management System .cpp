#include <iostream>
#include <stack>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

// Structure to represent an order
struct Order {
    int orderID;
    time_t timestamp;
    bool isPriority;
};

class Restaurant {
private:
    queue<Order> regularOrders; // Queue for regular orders
    stack<Order> priorityOrders; // Stack for priority orders

public:
    // Function to add an order
    void addOrder(bool isPriority) {
        Order newOrder;
        newOrder.orderID = rand() % 1000; // Generate random order ID
        newOrder.timestamp = time(nullptr); // Current timestamp
        newOrder.isPriority = isPriority;

        if (isPriority)
            priorityOrders.push(newOrder); // Add to priority stack
        else
            regularOrders.push(newOrder); // Add to regular queue

        cout << "New order added with ID: " << newOrder.orderID << " at time: " << ctime(&newOrder.timestamp) << endl;
    }

    // Function to process orders
    void processOrders() {
        while (!priorityOrders.empty()) {
            cout << "Processing priority order with ID: " << priorityOrders.top().orderID << endl;
            priorityOrders.pop();
        }

        while (!regularOrders.empty()) {
            cout << "Processing regular order with ID: " << regularOrders.front().orderID << endl;
            regularOrders.pop();
        }
    }

    // Function to display the status of the queue and stack
    void displayStatus() {
        cout << "Priority Orders Stack:" << endl;
        stack<Order> tempPriorityOrders = priorityOrders;
        while (!tempPriorityOrders.empty()) {
            Order tempOrder = tempPriorityOrders.top();
            cout << "Order ID: " << tempOrder.orderID << " - Timestamp: " << ctime(&tempOrder.timestamp) << endl;
            tempPriorityOrders.pop();
        }

        cout << "Regular Orders Queue:" << endl;
        queue<Order> tempRegularOrders = regularOrders;
        while (!tempRegularOrders.empty()) {
            Order tempOrder = tempRegularOrders.front();
            cout << "Order ID: " << tempOrder.orderID << " - Timestamp: " << ctime(&tempOrder.timestamp) << endl;
            tempRegularOrders.pop();
        }
    }
};

int main() {
    srand(time(nullptr)); // Seed for random number generator

    Restaurant restaurant;

    // Add some random orders for demonstration
    for (int i = 0; i < 5; ++i) {
        restaurant.addOrder(false); // Regular order
        restaurant.addOrder(true);  // Priority order
    }

    cout << "----- Processing Orders -----" << endl;
    restaurant.processOrders();
    
    cout << "----- Current Status -----" << endl;
    restaurant.displayStatus();

    return 0;
}
