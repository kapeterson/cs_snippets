#include <iostream>
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string>
#define ETHER_ADDR_LEN 6

// compile with g++ -I/usr/lib/pcap test.cpp -lpcap


using namespace std;


struct sniff_ethernet {
	u_char ether_dhost[ETHER_ADDR_LEN];
	u_char ether_shost[ETHER_ADDR_LEN];
	u_short ether_type;
};



void printUsage(){
	printf("Usage: test.cpp <filename>\n\n");
}
int main(int argc, char *argv[]){

	if ( argc < 2 || argc > 3 ) {
		printUsage();
		return 1;
	}

	// default is /home/pete/temp/capture/.pcap

	string file = argv[1];
	cout << "File is " << file << "\n";
	
	char errbuff[PCAP_ERRBUF_SIZE];

	pcap_t* pcap = pcap_open_offline(file.c_str(), errbuff);
	struct pcap_pkthdr *header;
	const struct sniff_ethernet *ethernet;

	const struct sniff_ip *ip;
	const u_char *data;

	u_int size_ip;
	int packetcount = 0;

	while ( int returnValue = pcap_next_ex(pcap, &header, &data ) >= 0 ){
		//printf( "packet %d\n", packetcount);

		ethernet  = (struct sniff_ethernet*)data;
		char tstring[50];
		sprintf(tstring, "OK %d\n", 1);
		printf("Packet %d Ethernet src: %02x:%02x:%02x:%02x\n", packetcount, ethernet->ether_dhost[0],
			ethernet->ether_dhost[1], ethernet->ether_dhost[2], ethernet->ether_dhost[3]);
		packetcount++;
	}
	return 0;
}
