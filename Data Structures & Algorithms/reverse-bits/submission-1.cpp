class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = n;
        ret = (ret >> 16) | (ret << 16); //16 bits
        ret = ((ret & 0xff00ff00) >> 8) | ((ret & 0x00ff00ff) << 8); //8 bits
        ret = ((ret & 0xf0f0f0f0) >> 4) | ((ret & 0x0f0f0f0f) << 4); //4 bits
        ret = ((ret & 0xcccccccc) >> 2) | ((ret & 0x33333333) << 2); //2 bits
        ret = ((ret & 0xaaaaaaaa) >> 1) | ((ret & 0x55555555) << 1); //1 bits
        return ret;
    }
};
