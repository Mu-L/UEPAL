// Copyright (C) 2023 Meizhouxuanhan.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/EditableText.h"
#include "Components/TextBlock.h"
#include "PALConfigMenu.generated.h"

/**
 * 
 */
UCLASS()
class PAL_API UPALConfigMenu : public UUserWidget
{
	GENERATED_BODY()

private:
	UEditableText* GameResourcePathText;

	UTextBlock* GameResourcePathErrorText;

public:
	UFUNCTION()
	void SelectGameResourcePath();

	UFUNCTION()
	void StartGame();

private:
	UWidget* BuildMenuLabel(FText Text);

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

	virtual void NativeConstruct() override;
};
