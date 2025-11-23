# GetCurrency
GetCurrency - Educational and just-for-fun project on С++

## Dependencies
* [cpr](https://github.com/libcpr/cpr)
* [Qt](https://www.qt.io/)
* [nlohmann_json](https://github.com/nlohmann/json)

## Build
At this stage it is assumed that QtCore and QtWidgets are installed

```shell
vcpkg install cpr nlohmann-json
vcpkg integrate install

cd GetCurrency
mkdir build && cd build

cmake .. -DCMAKE_TOOLCHAIN_FILE="Path to vcpkg.cmake" -DCMAKE_PREFIX_PATH="Path to Qt compiler(msvc2022_64 for example or another)"
cmake --build . --config RELEASE

cd Release
windeployqt --release GetCurrency.exe
```

## Usage 
Start exe file
