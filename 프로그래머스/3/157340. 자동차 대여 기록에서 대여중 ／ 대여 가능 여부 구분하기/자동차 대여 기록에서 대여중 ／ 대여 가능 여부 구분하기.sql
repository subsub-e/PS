# -- 코드를 입력하세요
# WITH V AS (SELECT CAR_ID
# FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
# WHERE START_DATE <= '2022-10-16' AND END_DATE >= '2022-10-16'
# ORDER BY CAR_ID)

# SELECT DISTINCT CAR_ID, CASE WHEN CAR_ID IN (SELECT * FROM V) THEN '대여중' ELSE '대여 가능' END AS AVAILABILITY
# FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
# ORDER BY CAR_ID DESC









WITH V AS (
    SELECT CAR_ID
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE START_DATE <= "2022-10-16" AND END_DATE >= "2022-10-16"
)


SELECT DISTINCT CAR_ID, CASE WHEN CAR_ID IN (SELECT * FROM V) THEN '대여중' ELSE '대여 가능' END AS AVAILABILITY
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
ORDER BY CAR_ID DESC