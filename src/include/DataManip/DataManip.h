#ifndef DATAAMANIP_H
#define DATAMANIP_H

#include <iostream>
#include <vector>
#include <utility>

class DataFrame {
    private:
        std::vector<std::vector<std::string>> data;
        std::vector<std::string> split(const std::string& s, char delimiter);
    public: 
        DataFrame(const std::string& filename);
        void head(int n);
};

#endif // DATAMANIP_H
```
