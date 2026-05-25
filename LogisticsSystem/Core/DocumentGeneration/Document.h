#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

class Document {
public:
    std::string header;
    std::string body;
    std::string footer;

    std::string getFullText() const {
        return header + "\n\n" + body + "\n\n" + footer;
    }
};

#endif