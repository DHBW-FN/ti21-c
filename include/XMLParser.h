/*
 * Editors: Tobias Goetz
 */

#include <xercesc/sax/HandlerBase.hpp>
XERCES_CPP_NAMESPACE_USE

#ifndef PROGRAMMING_C_XMLPARSER_H
#define PROGRAMMING_C_XMLPARSER_H


#include <string>
#include <codecvt>
#include <locale>
#include "StateMachine.h"
#include "models/GetOptSetup.h"

using namespace std;

/**
 * @brief Class for the XMLParser
 */
class XMLParser : public HandlerBase {
private:
    /**
     * @brief filename
     * Name of the file to parse.
     */
    std::string filename;

    /**
     * @brief stateMachine
     * StateMachine to parse the file.
     */
    StateMachine *sm = new StateMachine();

    /**
     * @brief getOptSetup
     * GetOptSetup to parse the file.
     */
    GetOptSetup *getOptSetup = new GetOptSetup();
public:
    /**
     * @brief XMLParser
     * Constructor.
     * @param filename
     */
    explicit XMLParser(const string &filename);

    /**
     * @brief The main parser function.
     */
    void parse();

    void startDocument() override;
    void endDocument() override;
    void startElement(const XMLCh* name, AttributeList& attributes) override;
    void endElement(const XMLCh* name) override;
    void characters(const XMLCh* chars, XMLSize_t length) override;

    /**
     * @brief getGetOptSetup
     * @return getOptSetup
     */
    GetOptSetup *getGetOptSetup() const;
};


#endif //PROGRAMMING_C_XMLPARSER_H
