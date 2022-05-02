#!/usr/bin/env python3


def grep(pattern):
    while True:
        line = yield
        if pattern in line:
            print(line)


def test1():
    g = grep("python")
    g.__next__()  # TypeError: can't send non-None value to a just-started generator
    g.send("python")
    g.send("python is good")


def consumer(func):
    def wrapper(*args, **kwargs):
        f = func(*args, **kwargs)
        next(f)
        return f

    return wrapper


@consumer
def grep2(pattern):
    while True:
        line = yield
        if pattern in line:
            print(line)


def test2():
    g = grep2("python")
    g.send("python3 is good")
    g.close()
    #  g.send("python3 is good")  # raise StopIteration


@consumer
def grep3(pattern):
    try:
        while True:
            line = yield
            if pattern in line:
                print(line)
    except GeneratorExit:
        print("exiting")


def test3():
    g = grep3("python")
    g.send("python3 is good")
    g.close()


def main():
    test1()
    test2()
    test3()


if __name__ == "__main__":
    main()
