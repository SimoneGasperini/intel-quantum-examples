To run the examples in this repository you need to remotely connect to the [Intel DevCloud](https://www.intel.com/content/www/us/en/developer/tools/devcloud/overview.html) platform via SSH:

```bash
ssh devcloud
```

Once you're connected, type the following command to compile your hybrid classical-quantum program:

```bash
/glob/development-tools/intel-quantum-sdk/intel-quantum-compiler -v <my_quantum_program>.cpp
```

Finally, you can launch the created executable typing the command:

```bash
./<my_quantum_program>
```