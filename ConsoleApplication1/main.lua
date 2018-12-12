print ("lua init")

function Initialize()
	Start()
end



dialogueTree = 
{
	[1] =
		{
			[1] = {
				dialogProgress=2
			},
			[2] = {
				text = "Hello Stranger! Can you help me?\n1:Yes.\n2:No.",
				answerOne = 3,
				answerTwo = 2
			},
			[3] = {
				text = "Can you please tell me whats the weather today?\nI didnt follow school course about weather...\n1:It's sunny today.\n2:No!",
				
				answerOne = 4,
				answerTwo = 3
			},
			[4] = {
				text = "Thanks! you are hero! \n1: slowly go away...",
				
				answerOne = 4,
				answerTwo = 0
			}
		},
	[2] =
		{
			[1] = {
				dialogProgress=2
			},
			[2] = {
				text = "Hello Stranger! How's life?\n1: Not bad after all!\n2: I dont have time for this.",
				answerOne = 3,
				answerTwo = 2
			},
			[3] = {
				text = "I used to be a stranger like you, then I took an arrow in the knee..\n1: FUS RO DAH\n2: I am dark souls fan...",
				
				answerOne = 5,
				answerTwo = 4
			},
			[4] = {
				text = "...\n1: Leave",
				
				answerOne = 4,
				answerTwo = 0
			},
			[5] = {
				text = "the guy seems like dreaming about something very far away from here...\n1: Take your leave.",
				
				answerOne = 5,
				answerTwo = 0
			}
		}
}

dialogIndex=1
GameObjects={}
speed=3
dialogStarted=false;
x=0
y=0
function Start()

print("Start init")
	GameObjects[1]=Game.CreateGameObject("Player","Player","../assets/spriteSheet.png",0,100)
	GameObjects[2]=Game.CreateGameObject("npc1","Player","../assets/spriteSheet.png",-300,200)
	GameObjects[3]=Game.CreateGameObject("npc2","Player","../assets/spriteSheet.png",300,200)
	
	x=Game.GetPositionX(GameObjects[1])
	y=Game.GetPositionY(GameObjects[1])
	-- Game.SetViewCenter(x,y)
	backGround=Game.DrawSprite("../assets/backGround.png",450,450,-700,-600,4,4)
	Game.SetCollisionBox(GameObjects[1],32,64)
	Game.SetCollisionBox(GameObjects[2],50,85)
	Game.SetCollisionBox(GameObjects[3],50,85)
	
	

	
end

function Update()
	
	
	
	
	if dialogStarted==true then
		progress=dialogueTree[dialogIndex][1].dialogProgress
		 Game.SetDialogueText(dialogueTree[dialogIndex][progress].text)
		 Game.ShowDialogue(true)

		 
		 --old version of dialogue choice selection ( now I use KeyUp event)
		 -- if Game.KeyPressed("1") and pressed == false then
			-- if sentenceIndex==3 then dialogStarted=false
			-- end
			-- i=dialogueTree[dialogIndex][sentenceIndex].answerOne
			-- sentenceIndex=i
			-- timePressed = Game.Time()
			-- pressed=true
		 
		 
		 --dialogue choice selection (1 or 2)
		if Game.KeyUp("1")  then
			
			answer=dialogueTree[dialogIndex][progress].answerOne
			
			if dialogueTree[dialogIndex][progress].answerTwo==0 then dialogStarted=false end
			dialogueTree[dialogIndex][1].dialogProgress=answer
		end
		if Game.KeyUp("2") and dialogueTree[dialogIndex][progress].answerTwo~=0 then
			
			answer=dialogueTree[dialogIndex][progress].answerTwo
			dialogueTree[dialogIndex][1].dialogProgress=answer
			dialogStarted=false
		end
	end
	
	
	if	Game.KeyPressed("Escape") then
		print("Closing game")
		Game.CloseGame()
	end
	
	
	 if Game.Collide(GameObjects[1],GameObjects[2]) then
		
		if dialogStarted==false then
			
			Game.ShowDialogue(true)
			Game.SetDialogueText("Press 'F' to talk")
		end
		
		
		if Game.KeyDown("F") then
			dialogIndex=1
			dialogStarted=true
		end 
		
		Game.BounceOff(GameObjects[1])
		
	elseif Game.Collide(GameObjects[1],GameObjects[3]) then
	
		if dialogStarted==false then
			Game.ShowDialogue(true)
			Game.SetDialogueText("Press 'F' to talk")
		end
		
		
		if Game.KeyDown("F") then
			dialogIndex=2
			dialogStarted=true
		end 
		
		Game.BounceOff(GameObjects[1])
	else
		Game.ShowDialogue(false)
	end
	
	
	if dialogStarted==false then 
	
		if Game.KeyPressed("W") then
			Game.MoveObject(GameObjects[1],0,-speed)
	
		elseif Game.KeyPressed("S") then
			Game.MoveObject(GameObjects[1],0,speed)
	
		elseif Game.KeyPressed("A") then
			Game.MoveObject(GameObjects[1],-speed,0)
	
		elseif Game.KeyPressed("D") then
			Game.MoveObject(GameObjects[1],speed,0)
		end
	end
	
	--Updating window view at last to make it smooth
	--Order matters: first, update player position and then position window view
	x=Game.GetPositionX(GameObjects[1])
	y=Game.GetPositionY(GameObjects[1])
	Game.SetViewCenter(x,y)
	
	
end
