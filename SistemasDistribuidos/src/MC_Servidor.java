import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class MC_Servidor {
	
	public static void main(String[] args) throws Exception
	{
		int porta = 1970;
        ServerSocket socket = new ServerSocket(porta);
        System.out.println("Servidor iniciado na porta " + porta);
        while(true) {
        	Socket cliente = socket.accept();
        	System.out.println("Conexão iniciada com " + cliente.getInetAddress());
        	ObjectOutputStream saida = new ObjectOutputStream(cliente.getOutputStream());
        	saida.flush();
        	saida.writeObject(new Mensagem());
        	saida.close();
        	cliente.close();
        }
	}
	
	public static Mensagem getRequest()
	{
		Mensagem retorno = new Mensagem();
		return retorno;
	}
	
	public void sendReply(Mensagem resposta, InetAddress IPCliente, int PortaCliente) 
	{
		
	}
}
