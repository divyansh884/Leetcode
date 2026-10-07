SELECT w.id
FROM Weather AS w
JOIN Weather AS prev
ON DATEDIFF(w.recordDate, prev.recordDate) = 1
AND w.temperature > prev.temperature;