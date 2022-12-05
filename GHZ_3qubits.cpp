#include <iostream>
#include <string>
#include <map>

#include <clang/Quantum/quintrinsics.h>
#include <quantum.hpp>


const int N = 3;
qbit qreg[N];
cbit creg[N];

quantum_kernel void quantum_circuit()
{
    for (int i = 0; i < N; i++)
    {
        PrepZ(qreg[i]); //set the initial state to |000>
    }

    H(qreg[0]);
    CNOT(qreg[0], qreg[1]);
    CNOT(qreg[0], qreg[2]);

    for (int i = 0; i < N; i++)
    {
        MeasZ(qreg[i], creg[i]); //measure all the qubits
    }
}


int main()
{
    //setup quantum device simulator
    iqsdk::Iqs_Config iqs_config(N, "noiseless");
    iqsdk::Full_State_Simulator iqs_device(iqs_config);
    if (iqsdk::QRT_ERROR_SUCCESS != iqs_device.ready()) {
      return 1;
    }

    int shots = 1000;
    std::map<std::string, int> counts;

    for (int k = 0; k < shots; k++)
    {
        quantum_circuit();
        std::string r = "";
        for (int i = 0; i < N; i++)
        {
            r += std::to_string((int)creg[i]);
        }
        counts[r]++;
    }

    std::cout << "{ ";
    for (auto& x : counts)
    {
        std::cout << "'" << x.first << "': " << x.second << ", ";
    }
    std::cout << "}\n";

    return 0;
}
