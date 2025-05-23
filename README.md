POSIX libmpix example
=====================

An example application that runs on any supported [Zephyr board][1].

[1]: https://docs.zephyrproject.org/latest/boards/index.html

First follow the [Getting Started Guide][2] from Zephyr documentation to get a working
build environment.

[2]: https://docs.zephyrproject.org/latest/develop/getting_started/index.html


```sh
# Prepare the workspace
mkdir -p ~/zephyrproject_libmpix
cd ~/zephyrproject_libmpix

# Clone the example and its dependencies
west init -m https://github.com/libmpix/libmpix_example_zephyr
west update

cd libmpix_example_zephyr

# Build the project, for instance on the native simulator
west build -b native_sim

# Run the example application with output on the console
west flash
```
