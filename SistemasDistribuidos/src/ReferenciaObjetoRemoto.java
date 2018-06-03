import java.net.InetAddress;
import java.util.Date;

public class ReferenciaObjetoRemoto {
	private InetAddress enderecoIP;
	private int numeroPorta;
	private Date hora;
	private int numeroObjeto;
	
	public InetAddress getEnderecoIP() {
		return enderecoIP;
	}
	public void setEnderecoIP(InetAddress enderecoIP) {
		this.enderecoIP = enderecoIP;
	}
	public int getNumeroPorta() {
		return numeroPorta;
	}
	public void setNumeroPorta(int numeroPorta) {
		this.numeroPorta = numeroPorta;
	}
	public Date getHora() {
		return hora;
	}
	public void setHora(Date hora) {
		this.hora = hora;
	}
	public int getNumeroObjeto() {
		return numeroObjeto;
	}
	public void setNumeroObjeto(int numeroObjeto) {
		this.numeroObjeto = numeroObjeto;
	}	
}