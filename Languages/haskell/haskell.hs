 {- |
Module      :  Haskell.hs
Description :  Dijkstra's Algorithm in Haskell
Name        :  John Buckley III    
Maintainer  :  johebuck@ut.utm.edu	
Stability   :  unstable
      
<module description starting at first column>
-}

--dijkstra :: [(Char,Char,Int)]->Char->Char->[(Int,Char)]
-- graph :: [(Char, Char, Integer)] //node, node, weight
-- start :: [char]
-- end :: [char]

-- Things I'll probably need:
-- 1) Represent a graph via tuples 
-- 2) Designate start
-- 3) Designate end
-- 4) Find min distances 
-- 5) Sum distances/weights
-- 6) find min distance between sorce node and destination node


import Data.List
import Data.Char

-- 1) Represent a graph via tuples
graph::[(Char,Char,Int)]
graph=[('a','b',4),('a','h',10),('b','c',8),('b','h',11),('c','d',7),('c','f',4),('d','d',14),('d','c',9),('c','f',10),('f','g',2),('g','h',1),('g','i',6),('h','i',7)]

fst'::(x,x1,x2)->x
fst' (node1,_,_)=node1

snd'::(x,x1,x2)->x1
snd' (_,node2,_)=node2

thd'::(x,x1,x2)->x2
thd' (_,_,weight)=weight

-- 2) Designate start
start::[Char]
start=fst' (head graph):[]

-- 3) Designate end
end::[Char]
end=snd' (last graph):[]

--dijkstra :: [(Char,Char,Int)]->Char->Char->[(Int,Char)]

--Find min distances between nodes
minimum'::Ord n => [(x,x1,n)]->[(x,x1,n)]->[(x,x1,n)]
minimum' [] [] = []
minimum' [z] [] = [z]
minimum' [] [y] = [y]
minimum' [z] [y] 
 | thd' z < thd' y = z:[]
 | thd' y < thd' z = y:[]
 | otherwise=y:[]

--Find min distances between nodes recursive
minimumR::Ord n => [(x,x1,n)]->[(x,x1,n)]
minimumR [] = []
minimumR (x:xs) = minimum' [x] (minimumR xs)

-- 5) Sum distances/weights
sumWeight::Num n => [(x,x1,n)]->n
sumWeight (x:xs) = foldl (+) (thd' x) [thd' y | y <- xs]

