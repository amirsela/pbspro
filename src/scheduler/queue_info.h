/*
 * Copyright (C) 1994-2018 Altair Engineering, Inc.
 * For more information, contact Altair at www.altair.com.
 *
 * This file is part of the PBS Professional ("PBS Pro") software.
 *
 * Open Source License Information:
 *
 * PBS Pro is free software. You can redistribute it and/or modify it under the
 * terms of the GNU Affero General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * PBS Pro is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.
 * See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Commercial License Information:
 *
 * For a copy of the commercial license terms and conditions,
 * go to: (http://www.pbspro.com/UserArea/agreement.html)
 * or contact the Altair Legal Department.
 *
 * Altair’s dual-license business model allows companies, individuals, and
 * organizations to create proprietary derivative works of PBS Pro and
 * distribute them - whether embedded or bundled with other software -
 * under a commercial license agreement.
 *
 * Use of Altair’s trademarks, including but not limited to "PBS™",
 * "PBS Professional®", and "PBS Pro™" and Altair’s logos is subject to Altair's
 * trademark licensing policies.
 *
 */

#ifndef _QUEUE_INFO_H
#define _QUEUE_INFO_H
#ifdef	__cplusplus
extern "C" {
#endif
#include <pbs_ifl.h>
#include "data_types.h"


/*
 *
 *      query_queues - creates an array of queue_info structs which contain
 *                      an array of jobs
 */
queue_info **query_queues(status *policy, int pbs_sd, server_info *sinfo);

/*
 *      query_queue_info - collects information from a batch_status and
 *                         puts it in a queue_info struct for easier access
 */
queue_info *query_queue_info(status *policy, struct batch_status *queue, struct server_info *sinfo);

/*
 *      new_queue_info - allocate and initalize a new queue_info struct
 */
queue_info *new_queue_info(int limallocflag);

/*
 *      free_queues - frees the memory for an array
 */
void free_queues(queue_info **qinfo, char free_jobs_too);

/*
 *      update_queue_on_run - update the information kept in a qinfo structure
 *                              when a job is run
 */
void update_queue_on_run(queue_info *qinfo, resource_resv *resresv, char *job_state);

/*
 *      free_queue_info - free space used by a queue info struct
 */
void free_queue_info(queue_info *qinfo);

/*
 *      dup_queues - duplicate the queues on a server
 */
queue_info **dup_queues(queue_info **oqueues, server_info *nsinfo);

/*
 *      dup_queue_info - duplicate a queue_info structure
 */
queue_info *dup_queue_info(queue_info *oqinfo, server_info *nsinfo);

/*
 *
 *	find_queue_info - find a queue by name
 *
 *	  qinfo_arr - the array of queues to look in
 *	  name - the name of the queue
 *
 *	return the found queue or NULL
 *
 */
queue_info *find_queue_info(queue_info **qinfo_arr, char *name);

/*
 *      update_queue_on_end - update a queue when a job has finished running
 */
void
update_queue_on_end(queue_info *qinfo, resource_resv *resresv,
	char *job_state);

int queue_in_partition(queue_info *qinfo);


#ifdef	__cplusplus
}
#endif
#endif /* _QUEUE_INFO_H */

