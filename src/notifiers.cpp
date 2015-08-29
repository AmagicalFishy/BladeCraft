#include "notifiers.hpp"
#include <iostream>

//====================
// Notifier Base Class
void Notifier::notify() {
    std::set<Handler*>::iterator handlers = 
        registeredHandlers_.begin();
    while (handlers != registeredHandlers_.end()) {
        (*handlers)->recieveNotification();
        ++handlers;
    }
}

void Notifier::regHandler(Handler* handler) {
    registeredHandlers_.insert(handler); 
}

void Notifier::unregHandler(Handler* handler) {
    registeredHandlers_.erase(handler);
}
