OBJS = main.cpp Graph.cpp Message.cpp Network.cpp Node.cpp Packet.cpp Path.cpp

ALL: NetworkSim

NetworkSim: $(OBJS)
	g++ -o NetworkSim $(OBJS)

clean:
	rm NetworkSim
