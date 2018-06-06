package javaservidor;

import java.rmi.RemoteException;

public class ObjetoRemoto  implements RMIInterfaceBase{
    protected ObjetoRemoto() throws RemoteException {
	super();
    }
    @Override
    public boolean HePrimo(int numero) throws RemoteException {
        return numero%2 != 0;
    }
}
