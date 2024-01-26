# LetMePass
Bypasses YouTube's version alert, used for using the latest supported version of the app on iOS 12/13.

# Contributing
Ok; I don't actually expect anyone to contribute TBH (I don’t really have an idea of any contributions that can even be made). But, if you want to contribute, feel free, it's greatly appreciated! README contributions are also appreciated.

The current version of the code is formatted to the YouTube logo. If you need a more readable version, this commit is the exact same code but formatted normally: [https://github.com/0xilis/LetMePass/blob/b6a0e5e37d6c9acbcba889ddfc8c69939490cbd0/dylib.c](https://github.com/0xilis/LetMePass/blob/b6a0e5e37d6c9acbcba889ddfc8c69939490cbd0/dylib.c).

# TODO
Not much. Or really anything I can think about, except more optimizations maybe.

# Compiling
Tweak the `Makefile` to point to a SDK that you have, and compile. (And yes, I do know that despite specifying -nostdlib that libSystem still gets linked... it's fine, I'm not even sure if iOS accepts dylibs without libSystem linked, I heard from someone else it doesn't accept executables without it linked so wouldn't surprise me, and that's really only there since Unsigncuts_macOS also had the nostdlib flag).

# Licensing
LetMePass is licensed under MIT.

# Repo

Available on my personal repo here: [https://0xilis.github.io/repo](https://0xilis.github.io/repo).
