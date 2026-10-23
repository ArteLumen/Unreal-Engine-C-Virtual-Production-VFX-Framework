
#include "UnifiedProductionActor.h"
#include "Camera/CameraComponent.h"
#include "Components/PointLightComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"


FVector UVFXMathLibrary::CalculateComplexWaveOffset(FVector CurrentPosition, float Time, float Amplitude)
{
    float OffsetZ = FMath::Sin(CurrentPosition.X * 0.01f + Time) * Amplitude;
    return FVector(CurrentPosition.X, CurrentPosition.Y, CurrentPosition.Z + OffsetZ);
}

AUnifiedProductionActor::AUnifiedProductionActor()
{
    PrimaryActorTick.bCanEverTick = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("VirtualCamera"));
    RootComponent = CameraComponent;

    LightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("StudioLight"));
    LightComponent->SetupAttachment(RootComponent);
}

void AUnifiedProductionActor::BeginPlay()
{
    Super::BeginPlay();
}

void AUnifiedProductionActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector NewLocation = GetExternalTrackingDataFromHardware();
    FRotator NewRotation = GetExternalRotationDataFromHardware();
    SetActorLocationAndRotation(NewLocation, NewRotation);

    float DynamicIntensity = 5000.0f + (FMath::Sin(GetWorld()->GetTimeSeconds()) * 1000.0f);
    LightComponent->SetIntensity(DynamicIntensity);
}

FVector AUnifiedProductionActor::GetExternalTrackingDataFromHardware()
{

  return FVector(0.0f, 0.0f, 150.0f);
}

FRotator AUnifiedProductionActor::GetExternalRotationDataFromHardware()
{

  return FRotator(0.0f, 90.0f, 0.0f);
}
