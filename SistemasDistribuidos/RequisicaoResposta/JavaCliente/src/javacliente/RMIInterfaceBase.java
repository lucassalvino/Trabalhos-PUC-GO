package javacliente;

import java.rmi.*;

public interface RMIInterfaceBase  extends Remote{
	public boolean HePrimo(int numero)throws RemoteException;
}
