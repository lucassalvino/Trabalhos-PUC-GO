package javacliente;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;        

public class MC_Cliente {
    private static RMIInterfaceBase look_up;	
    public static void main(String[] args)throws MalformedURLException, RemoteException, NotBoundException{
        look_up = (RMIInterfaceBase) Naming.lookup("//127.0.0.1/servidor");
        int num = 4;
        boolean resposta = look_up.HePrimo(num);
        System.out.println(resposta);
    }
}
