OBJS = ./files/main.cpp ./files/Graph.cpp ./files/Message.cpp ./files/Network.cpp ./files/Node.cpp ./files/Packet.cpp ./files/Path.cpp

ALL: NetworkSim

NetworkSim: $(OBJS)
	g++ -o NetworkSim $(OBJS)

clean:
	rm NetworkSim
