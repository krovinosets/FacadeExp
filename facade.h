#ifndef FACADE_H
#define FACADE_H

#include <iostream>

class App
{
private:
    std::string _name;
    int _status = notStarted;
    int _port = Default;
    enum Status {
        notStarted, Started, Default = 25222
    };

    void bindPort(){
        std::cout << "APP::" << _name << " started listening on port: " << _port << std::endl;
    }

public:
    App(std::string name, int port){
        _name = name;
        _port = port;
    }

    void start(){
        bindPort();
        std::cout << "APP::Console has started" << std::endl;
        _status = Started;
    }

    void checkOnStatus(){
        std::cout << "APP::" << _name << " started: " << _status << std::endl;
    }
};


class System
{
private:
    App appList[3] {
        {"Console", 25565},
        {"Proxy", 25566},
        {"DataBase", 25567}
    };
    enum applications {
        Console, Proxy, DataBase
    };
    System(){} // Требуется, чтобы работал синглтон

public:
    // Singleton Мэйерса
    // Стандарт языка программирования C++ гарантирует автоматическое
    // уничтожение статических объектов при завершении программы
    // ** Singleton обычно используется фасадом, поэтому он тут
    static System &getInstance() {
        static System instance;
        return instance;
    }

    void start(){
        std::cout << "System is starting..." << std::endl;
        startApplication(Console);
        checkOnStatus(Console);
        startApplication(Proxy);
        checkOnStatus(Proxy);
        startApplication(DataBase);
        checkOnStatus(DataBase);
    }

    void checkOnStatus(int id){
        appList[id].checkOnStatus();
    }

    void startApplication(int id){
        appList[id].start();
    }
};

#endif // FACADE_H
