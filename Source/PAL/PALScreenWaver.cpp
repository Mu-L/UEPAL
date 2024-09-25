// Copyright (C) 2022 Meizhouxuanhan.


#include "PALScreenWaver.h"
#include "PAL.h"

APALScreenWaver::APALScreenWaver() : APostProcessVolume()
{
	bUnbound = true;
	static ConstructorHelpers::FObjectFinder<UMaterial> ScreenWaveMaterialRef(TEXT("Material'/Game/PAL_ScreenWave.PAL_ScreenWave'"));
	ScreenWaveMaterialInstance = UMaterialInstanceDynamic::Create(ScreenWaveMaterialRef.Object, this);
	Settings.AddBlendable(ScreenWaveMaterialInstance, 1.f);
}

void APALScreenWaver::SetLevel(uint32 Level)
{
	if (ScreenWaveMaterialInstance)
	{
		ScreenWaveMaterialInstance->SetScalarParameterValue(TEXT("WaveLevel"), Level * 0.005 / 2);
	}
}

