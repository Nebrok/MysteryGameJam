// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreKeeping.h"


int UScoreKeeping::ResetScore()
{
	roomScore = 0;
	UE_LOG(LogTemp, Display, TEXT("CurrentScore: %d"), roomScore);
	return roomScore;
}

int UScoreKeeping::AddToScore()
{
	roomScore++;
	UE_LOG(LogTemp, Display, TEXT("CurrentScore: %d"), roomScore);
	return roomScore;
}