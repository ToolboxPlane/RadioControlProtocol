/**
 * @file lib. pp
 * @author Paul Nykiel
 * @version 0.1
 */

#define RC_LIB_START 0xC9
#define  RC_LIB_END 0x93

namespace rcLib{
    enum CheckSumStatus{
        MISSMATCH,
        MATCH,
        NOT_CHECKED
    }

    struct Package{
        uint8_t uid;
        uint8_t tid;
        uint16_t resolution;
        uint16_t* channelData;
        uint8_t checksum;
        CheckSumStatus checkSumStatus;
    }

    uint8_t tid = 0;
    uint16_t resolution = 0;
    uint8_t uid = 0;

    void init(uint8_t deviceId, uint16_t resolution);
    uint8_t* encode(uint16_t* channelData);
    uint8_t* encode(Package package);

    Package decode(uint8_t* data);
}
