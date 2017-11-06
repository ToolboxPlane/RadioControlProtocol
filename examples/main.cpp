#include <iostream>
#include <cstdint>

#include "../rcLib.hpp"

class Connection{
public:
    bool isAvailable(){
        return true;
    }

    uint8_t read(){
        char data;
        std::cin.get(data);

        return (uint8_t)data;
    }

    void send(uint8_t* data){
        std::cout << std::hex << data << std::endl;
    }
};

int main() {
    Connection connection;

    rcLib::Package packageSend(32, 4);
    packageSend.setChannel(0, 1);
    packageSend.setChannel(1, 2);
    packageSend.setChannel(2, 3);
    packageSend.setChannel(3, 4);
    packageSend.setMeshProperties(true, 7);

    uint8_t size = packageSend.encode();
    uint8_t* encoded = packageSend.getEncodedData();

    encoded[6] ^= 0b1 << 1;

    rcLib::Package packageReceive;
    int c=0;
    while(!packageReceive.decode(encoded[c++]));

    std::cout << (packageReceive.isChecksumCorrect()?"Stimmt":"Nicht") << std::endl;
    /*for(int c=0; c<100000000; c++){
        if(connection.isAvailable()){
            uint8_t packageFinished = package.decode(connection.read());
            if(packageFinished){
                if(package.isMesh() && package.needsForwarding()){
                    package.countNode();
                    connection.send(package.encode());
                }
                package = rcLib::Package();
            }
        }
    }*/
    return 0;
}