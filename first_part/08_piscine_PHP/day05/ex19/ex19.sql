SELECT ABS(DATEDIFF(MIN(release_date), MAX(last_projection))) AS 'uptime' 
FROM `film` 
WHERE release_date != 0
