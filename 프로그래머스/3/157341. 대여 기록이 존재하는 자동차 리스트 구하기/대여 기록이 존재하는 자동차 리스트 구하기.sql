# # -- 코드를 입력하세요
# # SELECT DISTINCT C.CAR_ID
# # FROM CAR_RENTAL_COMPANY_CAR C
# # JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY H ON C.CAR_ID = H.CAR_ID
# # WHERE C.CAR_TYPE = '세단' AND (START_DATE BETWEEN '2022-10-01' AND '2022-10-31')
# # ORDER BY CAR_ID DESC





# SELECT DISTINCT C.CAR_ID 
# FROM CAR_RENTAL_COMPANY_CAR C
# JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY H
# ON C.CAR_ID = H.CAR_ID
# WHERE C.CAR_TYPE = '세단' AND MONTH(START_DATE) = 10
# ORDER BY C.CAR_ID DESC







SELECT DISTINCT H.CAR_ID
FROM CAR_RENTAL_COMPANY_CAR C
JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY H ON C.CAR_ID = H.CAR_ID
WHERE C.CAR_TYPE = '세단' AND (H.START_DATE BETWEEN '2022-10-01' AND '2022-10-31')
ORDER BY H.CAR_ID DESC;







