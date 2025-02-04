# -- 코드를 입력하세요
# WITH V AS (SELECT FLAVOR, SUM(TOTAL_ORDER) AS TOTAL_ORDER
# FROM JULY
# GROUP BY FLAVOR)

# SELECT F.FLAVOR
# FROM FIRST_HALF F
# JOIN V ON F.FLAVOR = V.FLAVOR
# GROUP BY FLAVOR
# ORDER BY (F.TOTAL_ORDER + V.TOTAL_ORDER) DESC
# LIMIT 3;


WITH V AS (
SELECT FLAVOR, SUM(TOTAL_ORDER) AS TOTAL_ORDER
FROM JULY
GROUP BY FLAVOR)

SELECT F.FLAVOR
FROM FIRST_HALF F
JOIN V ON V.FLAVOR = F.FLAVOR
ORDER BY (F.TOTAL_ORDER + V.TOTAL_ORDER) DESC
LIMIT 3








