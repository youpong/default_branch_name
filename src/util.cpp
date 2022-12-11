/**
 * @file
 */
#include "util.h"

static void test_Command()
{
    Command c = Command::exec("ls Makefile"s);
    expect("Makefile\n"s, c.getOutput(), "getOutput()"s);
    expect(1, c.getOutputLines(), "getOutputLines()"s);

    c = Command::exec("true"s);
    expect(0, c.getExitCode(), "Exit code"s);

    c = Command::exec("false"s);
    expect(1, c.getExitCode(), "Exit code"s);
}

static void test_Path()
{
    // directory
    auto p = Path::of("/etc"s);
    expect(false, p.is_regular_file(), "test -f "s + p.to_s());
    expect(true, p.is_directory(), "test -d "s + p.to_s());
    expect(true, p.is_executable(), "test -x "s + p.to_s());

    // executable regular file
    p = Path::of("/bin/sh"s);
    expect(true, p.is_regular_file(), "test -f "s + p.to_s());
    expect(false, p.is_directory(), "test -d "s + p.to_s());
    expect(true, p.is_executable(), "test -x "s + p.to_s());

    // non-executable regular file
    p = Path::of("Makefile"s);
    expect(true, p.is_regular_file(), "test -f "s + p.to_s());
    expect(false, p.is_directory(), "test -d "s + p.to_s());
    expect(false, p.is_executable(), "test -x "s + p.to_s());

    // not existence path
    p = Path::of("not_existence"s);
    expect(false, p.is_regular_file(), "test -f "s + p.to_s());
    expect(false, p.is_executable(), "test -x "s + p.to_s());
    expect(false, p.is_directory(), "test -d "s + p.to_s());
}

/**
 * Tests belows.
 * * class Path
 * * class Command
 */
void test_util()
{
    test_Path();
    test_Command();
}
