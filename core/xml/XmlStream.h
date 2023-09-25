#ifndef XMLSTREAM_H
#define XMLSTREAM_H

#include "../../utils/Container.h"

#include <string>

namespace XmlStream {
    void saveData(const Container& container, const std::string& path);
    bool loadData(Container& container, const std::string& path);
}

#endif
