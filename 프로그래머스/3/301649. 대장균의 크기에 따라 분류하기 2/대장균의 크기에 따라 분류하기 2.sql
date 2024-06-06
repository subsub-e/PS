# -- 코드를 작성해주세요
WITH A AS (
SELECT ID,PERCENT_RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) AS SIZEPER
FROM ECOLI_DATA)

SELECT ID, CASE WHEN SIZEPER <= 0.25 THEN 'CRITICAL' WHEN SIZEPER <= 0.50 THEN 'HIGH' WHEN SIZEPER <= 0.75 THEN 'MEDIUM' ELSE 'LOW' END AS COLONY_NAME
FROM A
ORDER BY ID

# select a.id,
# case when a.per <= 0.25 then 'CRITICAL'
# when a.per <= 0.5 then 'HIGH'
# when a.per <= 0.75 then 'MEDIUM'
# else 'LOW' end COLONYNAME
# from
# (select id, PERCENTRANK() over (order by SIZEOFCOLONY desc) per
# from ECOLI_DATA ) a
# order by id;