#include "RemoteControllerPCH.h"

#include "RemoteControllerServer.h"

DEFINE_LOG_CATEGORY(ServerLog)

RemoteControllerServer::RemoteControllerServer(const FIPv4Endpoint& InServerEndpoint)
{
	StartServer(InServerEndpoint);
}

RemoteControllerServer::~RemoteControllerServer()
{
}

bool RemoteControllerServer::StartServer(const FIPv4Endpoint& endpoint)
{
	UE_LOG(ServerLog, Warning, TEXT("CloudyGame: RemoteController Server Started"));
	FTimespan ThreadWaitTime = FTimespan::FromMilliseconds(100);
	ServerSocket = FUdpSocketBuilder(TEXT("RemoteControllerServerSocket")).BoundToEndpoint(endpoint);
	InputReceiver = new FUdpSocketReceiver(ServerSocket, ThreadWaitTime, TEXT("Udp Input Receiver"));
	InputReceiver->OnDataReceived().BindRaw(this, &RemoteControllerServer::HandleInputReceived);
	UE_LOG(ServerLog, Warning, TEXT("CloudyGame: RemoteController Server Started Successfully"));
	return true;
}

void RemoteControllerServer::HandleInputReceived(const FArrayReaderPtr& Data, const FIPv4Endpoint& Sender)
{
	//FUdpControllerSegment::FDataChunk DataChunk;
	//*Data << DataChunk;
	UE_LOG(ServerLog, Warning, TEXT("CloudyGame: RemoteController Handling Data"));
	//UE_LOG(ServerLog, Warning, TEXT("Data: %d"), DataChunk.Data.GetData()[0]);
}