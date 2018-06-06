package javaservidor;

import java.rmi.RemoteException;
import java.rmi.Naming;
import java.rmi.Remote;
public class MC_Servidor{
    public static void main(String[] args) throws Exception
    {
        try {
            ObjetoRemoto obj = new ObjetoRemoto();
            System.setProperty( "java.rmi.server.hostname","127.0.0.1");
            Naming.rebind("servidor", (Remote) obj);            
            System.err.println("Server ready");
        } catch (RemoteException e) {
            System.err.println("Server exception: " + e.toString());
        }
    }
}