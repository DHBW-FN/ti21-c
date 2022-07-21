#ifndef CODEGENERATOR_HELPTEXT_H
#define CODEGENERATOR_HELPTEXT_H

#include "Justify.h"
#include "models/GetOptSetup.h"
#include <iostream>
#include <vector>

using namespace std;

class HelpText
{
public:
    explicit HelpText(GetOptSetup *getOptSetup);
    ~HelpText();

    string parseHelpMessage();
    void parseDescription();
    void parseUsage();
    void parseAuthor();
    void parseOption();

    string concatParams(int i);
    void getLength();
private:
    /**
     * @brief printHelp Text
     * stores the string for the printHelp method.
     */
    string printHelpText;
    /**
     * @brief Length of longest Parameter
     * Stores the length of the longest
     * parameter in options.
     */
    int optionParamLength = 0;
    /**
     * @brief shift
     * extra shift / space can be defined
     * for the space between parameters
     * and description in options.
     */
    const int shift = 5;
    /**
     * @brief Justify object
     */
    Justify justify;
    /**
     * @brief GetOptSetup object
     */
    GetOptSetup *getOptSetup;
};

#endif //CODEGENERATOR_HELPTEXT_H
