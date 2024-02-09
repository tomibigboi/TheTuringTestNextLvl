// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBPFileMangementFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class THETURINGTESTNEXTLVL_API UMyBPFileMangementFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	UFUNCTION(BlueprintCallable, Category = "FileMangement")
	static void CreateSaveFile(FString DataToBePassed);
	UFUNCTION(BlueprintCallable, Category = "FileMangement")
	static void DeleteSaveFile(FString SaveFileName);
	UFUNCTION(BlueprintCallable, Category = "FileMangement")
	static FString GetSaveFileData(int32 FileIndex);
	UFUNCTION(BlueprintCallable, Category = "FileMangement")
	static void UpdateASaveFile(FString DataToBePassed);
	UFUNCTION(BlueprintCallable, Category = "FileMangement")
	static void GetAllSaveFiles(TArray<FString>& myStringArray);
	UFUNCTION(BlueprintCallable, Category = "FileMangement")
	static int32 NumberOfSaveFiles();
	UFUNCTION(BlueprintCallable, Category = "FileMangement")
	static FString GetFileName(int32 FileIndex);

	static FString GetSaveDirectory();
	static const FString MySaveDirectory;


	
};
