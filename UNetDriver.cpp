// UNetDriver.cpp

ENetMode UNetDriver::GetNetMode() const
{
	// Special case for PIE - forcing dedicated server behavior
#if WITH_EDITOR // 에디터 상태에서는,
	if (World && World->WorldType == EWorldType::PIE && IsServer())
	{
		//@todo: world context won't be valid during seamless travel CopyWorldData
		FWorldContext* WorldContext = GEngine->GetWorldContextFromWorld(World);
		if (WorldContext && WorldContext->RunAsDedicated) // 데디로 실행했다면
		{
			return NM_DedicatedServer; // 데디 서버 반환.
		}
	}
#endif

	// Normal
	return (IsServer() ? (GIsClient ? NM_ListenServer : NM_DedicatedServer) : NM_Client);
		// 서버인데, 클라이언트로 참여하고 있다? 리슨서버. 서버인데 참여하고 있지 않다? 데디서버.
}
