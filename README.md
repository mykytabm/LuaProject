# LuaProject
C++ Lua framework
Allows to create branching dialogues and program all logic using Lua script.

*   Possible to create and add sprites to game objects from Lua file.
*   Possible to add colliders and check collision between objects in lua.
*   Create dialogues and its possible answers and outcomes in lua file.

## Dialogue Scripting example
```lua
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
				  text = "Can you please tell me whats the weather today?\nI didnt follow school course about weather...\n1:It's sunny                       today.\n2:No!",
				  answerOne = 4,
				  answerTwo = 3
			  },
			  [4] = {
				  text = "Thanks! you are hero! \n1: slowly go away...",	
				  answerOne = 4,
				  answerTwo = 0
			  }
		}
}
```

