// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBPFileMangementFunctionLibrary.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/FileHelper.h"
#include "HAL/FileManager.h"


const FString UMyBPFileMangementFunctionLibrary::MySaveDirectory = TEXT("C:/Users/toumi/Desktop/DesktopDirectory/");


void UMyBPFileMangementFunctionLibrary::CreateSaveFile(FString DataToBePassed)
{
	//create save file name by incrimenting on the number of save file already existing in game
	FString FIleName = FString::Printf(TEXT("GameSaveFile_%d.txt"),UMyBPFileMangementFunctionLibrary::NumberOfSaveFiles()+1);
	//ccreate the name of the files path by concatinating the testing directory with the file name
	FString FilePath = UMyBPFileMangementFunctionLibrary::MySaveDirectory+"/" + FIleName;
	UE_LOG(LogTemp, Error, TEXT("%s"),*FilePath);
	//create the file and pass it the default data
	bool Success = FFileHelper::SaveStringToFile(DataToBePassed, *FilePath);
	//check if it was succeful
	if (!Success) {
		// Display an error message or take other actions if the file writing failed.
		UE_LOG(LogTemp, Error, TEXT("Failed to create text file: %s"), *FilePath);
	}
}

void UMyBPFileMangementFunctionLibrary::DeleteSaveFile(FString SaveFileName)
{
	//ccreate the name of the files path by concatinating the testing directory with the file name
	FString FilePath = UMyBPFileMangementFunctionLibrary::MySaveDirectory + "/" + SaveFileName;
	bool Success = IFileManager::Get().Delete(*FilePath);
	//check if it was succeful
	if (!Success) {
		// Display an error message or take other actions if the file writing failed.
		UE_LOG(LogTemp, Error, TEXT("Failed to delete text file: %s"), *FilePath);
	}
}

void UMyBPFileMangementFunctionLibrary::UpdateASaveFile(FString DataToBePassed)
{
	//create save file name by incrimenting on the number of save file already existing in game
	FString FIleName = FString::Printf(TEXT("GameSaveFile_%d.txt"), UMyBPFileMangementFunctionLibrary::NumberOfSaveFiles() + 1);
	//ccreate the name of the files path by concatinating the testing directory with the file name
	FString FilePath = UMyBPFileMangementFunctionLibrary::MySaveDirectory + "/" + FIleName;
	UE_LOG(LogTemp, Error, TEXT("%s"), *FilePath);
	//create the file and pass it the default data
	bool Success = FFileHelper::SaveStringToFile(DataToBePassed, *FilePath);
	//check if it was succeful
	if (!Success) {
		// Display an error message or take other actions if the file writing failed.
		UE_LOG(LogTemp, Error, TEXT("Failed to create text file: %s"), *FilePath);
	}
}

FString UMyBPFileMangementFunctionLibrary::GetSaveFileData(int32 FileIndex)
{
	IFileManager& FileManager = IFileManager::Get();
	TArray<FString> DirectoryContents;
	const TCHAR* charArray = *UMyBPFileMangementFunctionLibrary::MySaveDirectory;
	FileManager.FindFiles(DirectoryContents, charArray, TEXT("*.txt"));
	FString ContentResult;
	FFileHelper::LoadFileToString(ContentResult, *DirectoryContents[FileIndex]);

	return ContentResult;
}

void UMyBPFileMangementFunctionLibrary::GetAllSaveFiles(TArray<FString>& myStringArray)
{
	IFileManager& FileManager = IFileManager::Get();

	const TCHAR* charArray = *UMyBPFileMangementFunctionLibrary::MySaveDirectory;
	FileManager.FindFiles(myStringArray, charArray, TEXT("*.txt"));
}


int32 UMyBPFileMangementFunctionLibrary::NumberOfSaveFiles()
{
	IFileManager& FileManager = IFileManager::Get();
	TArray<FString> DirectoryContents;
	const TCHAR* charArray = *UMyBPFileMangementFunctionLibrary::MySaveDirectory;
	FileManager.FindFiles(DirectoryContents, charArray, TEXT("*.txt"));
	//UE_LOG(LogTemp, Warning, FString::Printf(TEXT("Number of files of type %s: %d"),UMyBPFileMangementFunctionLibrary::Adrresse,0));
	return DirectoryContents.Num();
}

FString UMyBPFileMangementFunctionLibrary::GetFileName(int32 FileIndex)
{
	IFileManager& FileManager = IFileManager::Get();
	TArray<FString> DirectoryContents;
	const TCHAR* charArray = *UMyBPFileMangementFunctionLibrary::MySaveDirectory;
	FileManager.FindFiles(DirectoryContents, charArray, TEXT("*.txt"));
	return DirectoryContents[FileIndex];
}

//not BP Visible
FString UMyBPFileMangementFunctionLibrary::GetSaveDirectory()
{
	FString ExecPath = FPlatformProcess::ExecutablePath();
	//UE_LOG(LogTemp, Display, TEXT("%s"), *ExecPath);
	FString InstallationDir = FPaths::GetPath(ExecPath);
	FString SaveDirectory = ""; 
	InstallationDir.RemoveAt(InstallationDir.Find("Engine", ESearchCase::IgnoreCase, ESearchDir::FromStart), InstallationDir.Len(),true);
	return InstallationDir;
}


	