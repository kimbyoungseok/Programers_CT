// 액터 스폰시 호출되는 함수 - 로그 출력 테스트 : 액터를 스폰시키고, 콘솔에 로그 메세지가 출력되는지 확인한다.
void AAMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AMyActor has spawned!"));
}

// 이동 로직 설계 - 1. step 함수 구현
int32 AAMyActor::step()
{
	return FMath::RandRange(0, 1);
}

// 이동 로직 설계 - 2. move 함수 구현
void AAMyActor::move()
{
    start = FVector2D(0, 0);  // 시작 좌표 설정
    UE_LOG(LogTemp, Warning, TEXT("Starting Position: (%f, %f)"), start.X, start.Y);

    for (int i = 0; i < 10; i++)
    {
        int32 stepX = step();
        int32 stepY = step();

        // X와 Y 이동 제한
        if (start.X + stepX <= 2) start.X += stepX;
        if (start.Y + stepY <= 2) start.Y += stepY;

        // 현재 좌표 로그 출력
        UE_LOG(LogTemp, Warning, TEXT("Moved to Position: (%f, %f)"), start.X, start.Y);
    }
}


// Tick 함수 호출
void AAMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	move();  // 이동 함수 호출
}

