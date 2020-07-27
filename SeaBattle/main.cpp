#include <iostream>
#include "game_process.h"
#include "parcer/optionparser-1.7/src/optionparser.h"

enum  optionIndex {HELP, COUNT, FIRST, SECOND};

struct Arg: public option::Arg
{
    static void printError(const char* msg1, const option::Option& opt, const char* msg2)
    {
        fprintf(stderr, "%s", msg1);
        fwrite(opt.name, opt.namelen, 1, stderr);
        fprintf(stderr, "%s", msg2);
    }
    static option::ArgStatus Unknown(const option::Option& option, bool msg)
    {
        if (msg) printError("Unknown option '", option, "'\n");
        return option::ARG_ILLEGAL;
    }
    static option::ArgStatus Required(const option::Option& option, bool msg)
    {
        if (option.arg != 0)
            return option::ARG_OK;
        if (msg) printError("Option '", option, "' requires an argument\n");
        return option::ARG_ILLEGAL;
    }
    static option::ArgStatus NonEmpty(const option::Option& option, bool msg)
    {
        if (option.arg != 0 && option.arg[0] != 0)
            return option::ARG_OK;
        if (msg) printError("Option '", option, "' requires a non-empty argument\n");
        return option::ARG_ILLEGAL;
    }
    static option::ArgStatus Numeric(const option::Option& option, bool msg)
    {
        char* endptr = 0;
        if (option.arg != 0 && strtol(option.arg, &endptr, 10)){};
        if (endptr != option.arg && *endptr == 0)
            return option::ARG_OK;
        if (msg) printError("Option '", option, "' requires a numeric argument\n");
        return option::ARG_ILLEGAL;
    }
};

const option::Descriptor usage[] = {{HELP,0,"h", "help", option::Arg::None, "  \t--help  \tPrint usage and exit." },
                                    {COUNT,0,"c","count", Arg::Required," -c[<arg>], \t--optional[=<arg>]"},
                                    {FIRST,1,"f","first", Arg::Required,"  -f <arg>, \t--required=<arg>  \tMust have an argument." },
                                    {SECOND,2,"s","second", Arg::Required, "  -s <arg>, \t--required=<arg>  \\tMust have an argument." },{ 0, 0, 0, 0, 0, 0 }};

int main(int argc, char* argv[]) {

    argc -= (argc > 0);
    argv += (argc > 0); // skip program name argv[0] if present

    option::Stats stats(usage, argc, argv);
    option::Option options[stats.options_max], buffer[stats.buffer_max];
    option::Parser parse(usage, argc, argv, options, buffer);
    if (parse.error())
        return 1;
    if (options[HELP] || argc == 0) {
        option::printUsage(std::cout, usage);
    }
    if (parse.error())
        return 1;
    if (options[HELP] || argc == 0) {
        option::printUsage(std::cout, usage);
        return 0;
    }


    game_process new_game(buffer);
}