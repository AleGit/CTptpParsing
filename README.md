# CTptpParsing
Low level tptp parsing library and [Swift System Module](https://github.com/apple/swift-package-manager/blob/master/Documentation/SystemModules.md) to link against the library.

## Remark

Usually swift system modules are swift packages without any code, e.g. [CYices](https://github.com/AleGit/CYices).

## Installation

The tptp parsing library can be build and installed with `sudo make install`.

```
/usr/local/include/PrlcCore.h           # linux, macOS
/usr/local/include/PrlcData.h           # linux, macOS
/usr/local/include/PrlcMacros.h         # linux, macOS
/usr/local/include/PrlcPaser.h          # linux, macOS

/usr/lib/lib/libTtptpParsing.so         # linux
/usr/local/lib/libTptpParinsg.dylib     # macOS
```

## Usage

- See [CApiUsage](https://github.com/AleGit/CApiUsage).
- The library can be checked with `sudo make check` which builds and runs `checkTptpParsing`:
```
    > ./checkTptpParsing PUZ001-1.p 100
    PUZ001-1.p
    symbols: 317.1.2909 (11 % of 2909 bytes)
    p_nodes: 241.2056.2909 (8 % of 5980904 bytes)
    t_nodes: 106.40.2909 (4 % of 116360 bytes)
    »« »~« »|« »&« »-->« »,« »<=>« »=>« »<=« »<~>« »~|« »~&« »!« »?« »=« »!=«
    »PUZ001-1.p« »agatha« »hypothesis« »lives« »butler« »charles« »poorer_killer« »killed« »X« »Y«
    »richer« »different_hates« »hates« »no_one_hates_everyone« »agatha_hates_agatha«
    »agatha_hates_charles« »killer_hates_victim« »same_hates« »butler_hates_poor«
    »prove_neither_charles_nor_butler_did_it« »negated_conjecture« ¤
    ```
    
## Systems

- Ubuntu 14.04 LTS
- macOS Sierra 10.12 Beta
