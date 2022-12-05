To run the _GHZ_3qubits_ example in this repository you need first to connect to the [Intel DevCloud](https://www.intel.com/content/www/us/en/developer/tools/devcloud/overview.html) platform via SSH.
Once you are successfully connected to the login node, access the required computing resources typing the following command:
```bash
qsub -N GHZ_3qubits -l walltime=00:05:00 -l nodes=1:ppn=2 -I
```
Options:
- `-N GHZ_3qubits` to set the job name to _GHZ_3qubits_
- `-l walltime=00:05:00` to set the maximum time to 5 minutes
- `-l nodes=1:ppn=2` to reserve 1 computing node, 2 processors per node
- `-I` to enable "interactive mode"

Finally, you can compile the source code script by using the Intel Quantum compiler (`-v` for verbose) and run your hybrid classical-quantum program typing the following commands:

```bash
/glob/development-tools/intel-quantum-sdk/intel-quantum-compiler GHZ_3qubits.cpp
./GHZ_3qubits
```