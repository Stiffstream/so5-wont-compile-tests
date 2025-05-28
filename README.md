# Purpose

There are several checks in SObjectizer-5 that are implemented via
static_assert construct. There are also some cases of illegal use of
SObjectizer-5 that should lead to compilation errors. The problem is: how to
ensure that they work properly?

Unfortunately, we haven't found a good way to make this kind of testing
automatic and integrated into our CMake-based build process. Because of that
these tests have to be performed manually.

This repository is a collection of test cases that have to be run and checked
manually.

# How to use

## Ruby and Mxx_ru required

The SObjectizer-5 source code is included via Mxx_ru's mxxruexternals feature.
It means that Ruby and Mxx_ru are required.

For example, on Ubuntu/Kubuntu:

```sh
sudo apt install Ruby
sudo gem install Mxx_ru
```

## Obtaining and preparing

```sh
git clone https://github.com/stiffstream/so5-wont-compile-tests
cd so5-wont-compile-tests
mxxruexternals
mkdir cmake_build
cd cmake_build
cmake ..
```

## Testing

A list of test cases has to be obtained. If make- or Ninja-generators are used
then CMake with `--target help` argument should be run:

```sh
cmake --build . --target help
```

It may produce something like that:

```
$ cmake --build . --target help
The following are some of the valid targets for this Makefile:
... all (the default if no target is provided)
... clean
... depend
... edit_cache
... rebuild_cache
... message_limits.default_limit_then_transform
... message_limits.default_limit_then_transform_2
... message_limits.default_limit_then_transform_3
... message_limits.default_limit_then_transform_4
... message_limits.nonconst_ref_to_immutable_msg
... message_limits.nonconst_ref_to_immutable_msg_2
... mutable_msg.immutable_msg_as_argument
... mutable_msg.mutable_msg_as_argument
... mutable_msg.mutable_signal_send
... mutable_msg.mutable_signal_subscribe
... mutable_msg.mutable_signal_subscribe_lambda
... so_s.5.8.4
```

After that each test has to be run manually:

```sh
cmake --build . --target message_limits.default_limit_then_transform
cmake --build . --target message_limits.default_limit_then_transform_2
...
cmake --build . --target mutable_msg.mutable_signal_subscribe_lambda
```

