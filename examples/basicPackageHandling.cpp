/**
 * Simple program for basic mesh-node handling.
 * Requires some some sort connection in this example i use
 * uint8_t connection.isAvailable(), void connection.send(uint8_t* data) and
 * uint8_t connection.read()
 */
#include "lib.hpp"

int main(void) {
    rcLib::Package package();
    while(true){
        if(connection.isAvailable()){
            if(packageFinished){
                package = Package();
            }
            uint8_t packageFinished = package.decode(connection.read());
            if(packageFinished){
                if(package.isMesh() && package.needsForwarding()){
                    package.countNode();
                    connection.send(package.encode());
                }
                package = Package();
            }
        }
    }
    return 0;
}
