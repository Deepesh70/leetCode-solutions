# Write your MySQL query statement below
SELECT W1.id FROM Weather W1 JOIN 
Weather W2 ON DATEDIFF(W1.recordDate, w2.recordDate) = 1
WHERE W1.temperature > w2.temperature 